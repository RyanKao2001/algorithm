public class Main {
	
	private static int[][] board = new int[8][8];
	private static int total = 0;
	
	public static void main(String[] args) {
		backtrack(0);
	}

	private static void backtrack(int row) {
		// TODO Auto-generated method stub
		if(row == 8) {
			printBoard();
		}
		for (int i = 0; i < 8; i++) {
			if(!isValid(row, i)) continue;
			board[row][i] = 1;
			backtrack(row+1);
			board[row][i] = 0;
		}
	}

	private static boolean isValid(int row, int col) {
		// TODO Auto-generated method stub
		for (int j = 0; j < 8; j++) {
			if(board[j][col] == 1) return false; 
		}
		//检查左上方
		for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
			if(board[i][j] == 1) return false;
		}
		//检查右上方
		for (int i = row - 1, j = col + 1; i >= 0 && j < 8; i--, j++) {
			if(board[i][j] == 1) return false;
		}
		return true;
	}

	private static void printBoard() {
		// TODO Auto-generated method stub
		System.out.println("#" + (++total));
		for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board[i].length; j++) {
				System.out.print(board[i][j] + " ");
			}
			System.out.println();
		}
		System.out.println();
	}
}
