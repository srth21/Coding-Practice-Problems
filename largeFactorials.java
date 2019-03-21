/*
FInding the factorial of any large number

*/

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    static int multiply(int[] res, int ele, int size)
    {
        int carry = 0;

        for(int i=0;i<size;i++)
        {
            int product = res[i]*ele + carry;

            res[i] = product%10;

            carry = product/10;
        }

        while(carry!=0)
        {
            res[size] = carry%10;
            carry = carry/10;

            size++;
        }

        return size;
    
    }

    // Complete the extraLongFactorials function below.
    static void extraLongFactorials(int n) {

        int res[] = new int[1000];
        res[0] = 1;
        int size = 1;

        for(int i=2;i<=n;i++)
        {
            size = multiply(res,i,size);
        }

        for(int i=size-1;i>=0;i--)
        {
            System.out.print(res[i]);
        }
        System.out.print("\n");


    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        extraLongFactorials(n);

        scanner.close();
    }
}
