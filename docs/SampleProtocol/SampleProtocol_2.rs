/*
    Adding login/logout workflow
*/

protocol SampleProtocol(2,0)
{
    message LoginRequest
    {
        string Name;
    }

    message LoginAccept;

    message LoginReject
    {
        string Text;
    }

    message Logout
    {
        string Text;
    }

    enum Side
    {
        Bid,
        Ask
    }

    group SnapshotRefreshEntry
    {
        Side Side;
        int32 Qty;
        double Price;
        int32? Orders;
    }

    message SnapshotRefresh
    {
        string Symbol;
        SnapshotRefreshEntry[] Entries;
    }

    proc Client()
    {
        send Login(LoginRequest)
        {
            recv LoginAccept(LoginAccept)
            {
            }
            or recv LoginReject(LoginReject)
            {
                return;
            }
        }

        recv Snapshot(SnapshotRefresh)
        {
            repeat;
        }
        or send Logout(Logout)
        {
            recv Snapshot(SnapshotRefresh)
            {
                repeat;
            }
            or recv Logout(Logout)
            {
                return;
            }
        }
        or recv Logout(Logout)
        {
            return;
        }
    }

    proc Server()
    {
        recv Login(LoginRequest)
        {
            send (LoginAccept)
            {
            }
            or send (LoginReject)
            {
                return;
            }
        }

        send (SnapshotRefresh)
        {
            repeat;
        }
        or recv Logout(Logout)
        {
            send (SnapshotRefresh)
            {
                repeat;
            }
            or send (Logout)
            {
                return;
            }
        }
        or send (Logout)
        {
            return;
        }
    }
}