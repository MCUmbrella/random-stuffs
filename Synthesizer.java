import java.util.*;

public class Synthesizer
{
    public static String synthesize(String src, String pattern)
    {
        return synthesize(src, pattern.toCharArray());
    }

    public static String desynthesize(String src, String pattern)
    {
        return desynthesize(src, pattern.toCharArray());
    }

    public static String synthesize(String src, char[] pattern)
    {
        Set<Character> set = new HashSet<>();
        for(char c : pattern)
            set.add(c);
        StringBuilder sb = new StringBuilder(src.length());
        for(int i = 0; i != src.length(); i++)
            if(!set.contains(src.charAt(i)))
                 sb.append(src.charAt(i));
        return sb.toString();
    }

    public static String desynthesize(String src, char[] pattern)
    {
        Set<Character> set = new HashSet<>();
        for(char c : pattern)
            set.add(c);
        StringBuilder sb = new StringBuilder(src.length());
        for(int i = 0; i != src.length(); i++)
            if(set.contains(src.charAt(i)))
                sb.append(src.charAt(i));
        return sb.toString();
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        String src = sc.nextLine();
        String pattern = sc.nextLine();
        System.out.println(synthesize(src, pattern));
        System.out.println(desynthesize(src, pattern));
    }
}
