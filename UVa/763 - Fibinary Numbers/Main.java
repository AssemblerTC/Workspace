import java.util.*;
import java.math.*;
import java.io.*;
public class Main {
    public static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    public static int maxn = 110;
    public static BigInteger fibo[] = new BigInteger[maxn];
    public static BigInteger parse(String s) {
        BigInteger ans = BigInteger.ZERO;
        for (int i = s.length() - 1, p = 0; i >= 0; i--, p++)
            if (s.charAt(i) == '1')
                ans = ans.add(fibo[p]);
        return ans;
    }
    public static void main(String args[]) {
        fibo[0] = BigInteger.ONE;
        fibo[1] = new BigInteger("2");
        for (int i = 2; i < maxn; i++)
            fibo[i] = fibo[i - 2].add(fibo[i - 1]);
        boolean sw = false;
        try {
            while (true) {
                if (sw) in.readLine(); 
                BigInteger a = parse(in.readLine()).add(parse(in.readLine()));
                String ans = "";
                boolean zero = true;
                for (int i = maxn - 1; i >= 0; i--) {
                    if (fibo[i].compareTo(a) <= 0) {
                        ans += "1";
                        zero = false;
                        a = a.subtract(fibo[i]);
                    } else {
                        if (!zero)
                            ans += "0";
                    }
                }
                if (sw) System.out.println("");
                if (zero)
                    System.out.println("0");
                else
                    System.out.println(ans);
                
                sw = true;
            }
        } catch (Exception e) {
            
        }
    }
}
