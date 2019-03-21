/*

Alice is playing an arcade game and wants to climb to the top of the leaderboard and wants to track her ranking. The game uses Dense Ranking, so its leaderboard works like this:

The player with the highest score is ranked number  on the leaderboard.
Players who have equal scores receive the same ranking number, and the next player(s) receive the immediately following ranking number.
For example, the four players on the leaderboard have high scores of , , , and . Those players will have ranks , , , and , respectively. If Alice's scores are ,  and , her rankings after each game are ,  and .

Function Description

Complete the climbingLeaderboard function in the editor below. It should return an integer array where each element represents Alice's rank after the  game.

climbingLeaderboard has the following parameter(s):

scores: an array of integers that represent leaderboard scores
alice: an array of integers that represent Alice's scores
Input Format

The first line contains an integer , the number of players on the leaderboard. 
The next line contains  space-separated integers , the leaderboard scores in decreasing order. 
The next line contains an integer, , denoting the number games Alice plays. 
The last line contains  space-separated integers , the game scores.

*/

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the climbingLeaderboard function below.
    static int[] climbingLeaderboard(int[] scores, int[] alice) {

        int[] ranks = new int[200000];
        int[] return_ = new int[alice.length];
        for(int i=0;i<scores.length;i++)
        {
            if(i==0)
            {
                ranks[i] = 1;
            }
            else{
                if(scores[i] == scores[i-1])
                {
                    ranks[i] = ranks[i-1];
                }
                else
                {
                    ranks[i] = ranks[i-1] + 1;
                }
            }
        }

        int end = scores.length - 1;

        for(int j=0;j<alice.length;j++)
        {
            while(end>=0 && alice[j] > scores[end])
            {
                end--;
            }

            if(end == -1)
            {
                return_[j]  = 1;
            }
            else{
                if(alice[j] == scores[end])
                {
                    return_[j] = ranks[end];
                }
                else{
                    return_[j] = ranks[end]+1;
                }
            }
        }

        return return_;


    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int scoresCount = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] scores = new int[scoresCount];

        String[] scoresItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < scoresCount; i++) {
            int scoresItem = Integer.parseInt(scoresItems[i]);
            scores[i] = scoresItem;
        }

        int aliceCount = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] alice = new int[aliceCount];

        String[] aliceItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < aliceCount; i++) {
            int aliceItem = Integer.parseInt(aliceItems[i]);
            alice[i] = aliceItem;
        }

        int[] result = climbingLeaderboard(scores, alice);

        for (int i = 0; i < result.length; i++) {
            bufferedWriter.write(String.valueOf(result[i]));

            if (i != result.length - 1) {
                bufferedWriter.write("\n");
            }
        }

        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
