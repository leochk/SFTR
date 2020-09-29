// =========================================================
// class Cameleon
// =========================================================
public class Cameleon extends Thread {
    private Server server;
    private IdCameleon id;
    private Color myColor, otherColor;

    public Cameleon(Server m, IdCameleon id, Color c) {
        this.server = m;
        this.id = id;
        this.myColor = c;
    }

    private void Message(String Mess) {
        System.out.println("(" + id.toString() + ") I am " +
                myColor.toString() + " and " + Mess);
    }

    private void Repos() {
        Message("I am Eating Honey");
    }

    private void GoingToTheMall() {
        Message("I am going to the server");
    }

    private void Mutating() {
        Message("I am going to mute");
        otherColor = server.Cooperation(id, myColor);
        myColor = myColor.ComplementaryColor(otherColor);
        Message("I have done a mutation");
    }

    public void run() {
        while (true) {
            Repos();
            GoingToTheMall();
            Mutating();
        }
    }
}