import java.util.HashSet;

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
        HashSet<Character> set=new HashSet<>();
        for(char c : pattern) set.add(c);
        StringBuilder sb=new StringBuilder();
        for(int i=0; i!=src.length(); i++)
            if(!set.contains(src.charAt(i))) sb.append(src.charAt(i));
        return sb.toString();
    }
    public static String desynthesize(String src, char[] pattern)
    {
        HashSet<Character> set=new HashSet<>();
        for(char c : pattern) set.add(c);
        StringBuilder sb=new StringBuilder();
        for(int i=0; i!=src.length(); i++)
            if(set.contains(src.charAt(i))) sb.append(src.charAt(i));
        return sb.toString();
    }

    public static void main(String[] args)
    {
        String test="my name is van. im an artist. im a performance artist. im hired for people to fulfill their fantasies, their deep dark fantasies.";
        System.out.println(test);
        System.out.println(synthesize(test, "hired"));
        System.out.println(desynthesize(test, "hired"));
    }
}
