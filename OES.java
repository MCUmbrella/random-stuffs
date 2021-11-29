// odd/even statistic
public class OES
{
    public static int[] statistic(int[] a)
    {
        int odd=0;
        int even=0;
        for(int i:a)
            if(i>0)
                if(i%2==0) even++;
                else odd++;
            else throw new IllegalArgumentException("Data must be positive");
        return new int[]{odd,even};
    }

    public static void main(String[] args)// testing area
    {
        int[] q=statistic(new int[]{1, 14, 5, 141, 9, 8, 10});
        System.out.println("odd: "+q[0]+"\neven: "+q[1]);
    }
}
