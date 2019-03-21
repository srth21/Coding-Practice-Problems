import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;
import java.lang.Math;

public class Solution {

    // Complete the squares function below.
    static int squares(int a, int b) {

        if(a==b && (Math.sqrt(a) - Math.floor(Math.sqrt(a))) == 0)
        {
            return 1;
        }
        double a_ = Math.sqrt(a);
        double b_ = Math.sqrt(b);

        if(a_ == b_)
        {
            return 0;
        }
        int count =  (int)Math.ceil(b_) - (int)Math.ceil(a_); 
        
        
        if(b_ == Math.ceil(b_))
        {
            count+=1;
        }

        return count;


    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int q = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int qItr = 0; qItr < q; qItr++) {
            String[] ab = scanner.nextLine().split(" ");

            int a = Integer.parseInt(ab[0]);

            int b = Integer.parseInt(ab[1]);

            int result = squares(a, b);

            bufferedWriter.write(String.valueOf(result));
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
