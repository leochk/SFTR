// =========================================================
// class Server (Java)
// =========================================================
public class Server {
    private Color AColor, BColor;
    private boolean FirstCall = true;
    private boolean MustWait = false;
    private int mutex = 1;

    public synchronized Color Cooperation(IdCameleon x, Color C) {
        Color result;
        if (FirstCall) {
            AColor = C;
            FirstCall = false;
            while (!FirstCall && mutex == 0) {
                try {
                    wait();
                } catch (InterruptedException e) {
                }
            }
            mutex = 0;
            MustWait = false;
            result = BColor;
            mutex = 1;
            notifyAll();

        } else {
            BColor = C;
            result = AColor;
            FirstCall = true;
            notifyAll();
        }
        return result;
    }

}
