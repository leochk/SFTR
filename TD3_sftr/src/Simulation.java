// =========================================================
// class Simulation (the main class)
// =========================================================
public class Simulation {
    static Color[] TheColors =
            {Color.YELLOW,
                    Color.BLUE,
                    Color.RED,
                    Color.BLUE,
                    Color.YELLOW,
                    Color.BLUE
            };
    static Cameleon[] LesCameleons = new Cameleon[TheColors.length];

    public static void main(String args[]) {
        Server myMall = new Server();
        for (int i = 0; i < TheColors.length; i++) {
            LesCameleons[i] =
                    new Cameleon(myMall, new IdCameleon(i), TheColors[i]);
        }
        for (int i = 0; i < TheColors.length; i++) {
            LesCameleons[i].start();
        }
    }
}