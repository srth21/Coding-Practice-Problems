// Have the function LetterChanges(str) take the str parameter being passed and modify it using the following algorithm. 
// Replace every letter in the string with the letter following it in the alphabet (ie. c becomes d, z becomes a). 
// Then capitalize every vowel in this new string (a, e, i, o, u) and finally return this modified string. 


import java.util.*; 
import java.io.*;

class Main {  
    
    private static boolean isLetter(char c) {
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z');
}  
  public static String LetterChanges(String str) { 
  
    // code goes here   
    /* Note: In Java the return type of a function and the 
       parameter types being passed are defined, so this return 
       call must match the return type of the function.
       You are free to modify the return type. */
       
       String new_str = "";
       int l = str.length();
       
       for(int i = 0;i<l;i++)
       {
           char ch = str.charAt(i);
           if(isLetter(ch))
           {
               if(ch == 'z')
               {
                   new_str += 'A';
               }
               else
               {
                   char ch1 = (char) (ch + 1);
                   if(ch1 == 'e' || ch1 == 'i' || ch1 == 'o' || ch1 == 'u')
                   {
                       ch1 = (char)(ch1-32);
                   }
                   new_str += ch1;
               }
           }
           else
           {
               new_str += ch;
           }
           
           
       }
       
    return new_str;
    
  } 
  
  public static void main (String[] args) {  
    // keep this function call here     
    Scanner s = new Scanner(System.in);
    System.out.print(LetterChanges(s.nextLine())); 
  }   
  
}