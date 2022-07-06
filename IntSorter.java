import java.util.*;
public class IntSorter
{
    public static void main(String[] args)
    {
        TreeSet<Integer> a = new TreeSet<>();
        Scanner s = new Scanner(System.in);
        for(;;)
        {
            try {a.add(Integer.parseInt(s.nextLine()));}
            catch(Exception e) {break;}
        }
        for(Integer i : a) System.out.println(i);
    }
}
