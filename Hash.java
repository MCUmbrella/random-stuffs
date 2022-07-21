import java.util.Scanner;
import java.util.NoSuchElementException;

public class Hash
{
    final static StringBuilder sb = new StringBuilder();
    final static Scanner sc = new Scanner(System.in);
    public static void main(String... args)
    {
        if(args.length != 0)
            for(int i=0; i != args.length; i++)
                sb.append(args[i]).append(' ');
        else
            for(;;)
                try {sb.append(sc.nextLine()).append('\n');}
                catch (NoSuchElementException e) {break;}
        if(sb.length() != 0) sb.deleteCharAt(sb.length() - 1);
        System.out.println(sb.toString().hashCode());
    }
}
