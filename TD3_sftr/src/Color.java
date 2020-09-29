// =========================================================
// class Color
// =========================================================
public class Color {
    public int internalColor;
    private static final int blueInt = 0;
    private static final int redInt = 1;
    private static final int yellowInt = 2;
    public static final Color BLUE = new Color(blueInt);
    public static final Color RED = new Color(redInt);
    public static final Color YELLOW = new Color(yellowInt);

    private Color(int value) {
        internalColor = value % 3;
    }

    public Color ComplementaryColor(Color C) {
        if (internalColor == C.internalColor)
            return new Color(internalColor);
        else
            return new Color(3 - internalColor - C.internalColor);
    }

    public String toString() {
        if (internalColor == blueInt)
            return "blue";
        else if (internalColor == redInt)
            return "red";
        else
            return "yellow";
    }
}