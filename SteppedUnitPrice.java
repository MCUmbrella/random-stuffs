public class SteppedUnitPrice
{
    // my solution about a question i once saw about the algorithm for discounting based on the purchases
    public static float calculateUnitPrice(int count)
    {
        return count >= 20 ? 5.0f:
            count >= 15 ? 6.5f:
            count >= 10 ? 8.0f:
            count >= 5 ? 9.0f:
            10.0f;
    }
    
    public static void main(String[] args) // testing area
    {
        if(args.length==1)System.out.println(calculateUnitPrice(Integer.parseInt(args[0]))+"$/item, total price "+Float.parseFloat(args[0])*calculateUnitPrice(Integer.parseInt(args[0]))+"$");
    }
}
