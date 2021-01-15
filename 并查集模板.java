import java.util.Scanner;

public class Main {
    static boolean[] vis;
    static int n;
    static int[][] matrix;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int m = sc.nextInt();
        matrix = new int[n][n];
        for (int i = 0; i < m; i++) {
            int row = sc.nextInt();
            int col = sc.nextInt();
            matrix[row-1][col-1] = 1;
            matrix[col-1][row-1] = 1;
        }
        int ans = 0;
        vis = new boolean[n];
        for (int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(i);
                ans++;
            }
        }
        System.out.print(ans);
    }

    private static void dfs(int i) {
        vis[i] = true;
        for (int j = 0; j < n; j++) {
            if(matrix[i][j] == 1 && !vis[j]) {
                dfs(j);
            }
        }
    }
}
