import java.math.BigInteger;
import java.util.LinkedHashMap;
public class FFSW
{
    public static LinkedHashMap<BigInteger,BigInteger> findFactorialsStartWith(BigInteger count, BigInteger start, Boolean pwc)
    // count: how many "n!"s to be calculated
    // start: start with what
    // pwc: if hit a number, print immediately
    {
        LinkedHashMap<BigInteger,BigInteger> m=new LinkedHashMap<BigInteger,BigInteger>();
        String s=start.toString();
        BigInteger a=BigInteger.ONE;
        for(BigInteger i=BigInteger.ONE;i.compareTo(count)==-1||i.compareTo(count)==0;i=i.add(BigInteger.ONE))// i=1; i<=count; i++
        {
            a=a.multiply(i); // a*=i;
            if(a.toString().startsWith(s))
            {
                if(pwc)System.out.println("Hit: "+a.toString()+" ("+i.toString()+"!)");
                m.put(i,a);
            }
        }
        return m;
    }
    
    public static void main(String[] args)
    {
        if(args.length==3)System.out.println(findFactorialsStartWith(new BigInteger(args[0]),new BigInteger(args[1]),false));
        else if(args.length==2)
        {
            LinkedHashMap<BigInteger,BigInteger> r=findFactorialsStartWith(new BigInteger(args[0]),new BigInteger(args[1]),true);System.out.println("Completed: "+r.size()+" hit(s)");
            for(BigInteger i : r.keySet()){System.out.print(i.toString()+"! ");}System.out.println();
        }
    }
} 
