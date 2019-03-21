//Program to print the longest word in a String

import java.util.*; 
import java.io.*;

class Main { 
    
private static boolean isLetterOrDigit(char c) {
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           (c >= '0' && c <= '9');
}    
  public static String LongestWord(String sen) { 
  
    // code goes here   
    /* Note: In Java the return type of a function and the 
       parameter types being passed are defined, so this return 
       call must match the return type of the function.
       You are free to modify the return type. */
       int n = sen.length();
       String sen_new = "";
       
       for(int i=0;i<n;i++)
       {
           char ch =sen.charAt(i);
           if( isLetterOrDigit(ch) == true || ch == ' ')
           {
               sen_new += ch;
           }
       }
       
      
       sen_new += ' ';
       n = sen_new.length();
       //System.out.println(sen_new);
       int l,u,prev;
       
       l = 0;
       prev = 0;
       u = -1;
       
       for(int i=0;i<n;i++)
       {
           if(sen_new.charAt(i) == ' ')
           {
               if(u == -1)
               {
                   l = prev;
                   u = i-1;
               }
               
               else if (i-prev  > u-l+1)
               {
                   l = prev;
                   u = i;
               }
               prev = i+1;
           }
       }
       
       if(prev == 0 && u ==-1)
       {
           return sen_new;
       }
       sen = sen_new.substring(l,u+1);
       
    return sen;
    
  } 
  
  public static void main (String[] args) {  
    // keep this function call here     
    Scanner s = new Scanner(System.in);
    System.out.print(LongestWord(s.nextLine())); 
  }   
  
}