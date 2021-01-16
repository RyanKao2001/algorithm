import java.util.ArrayList;
import java.util.List;

public class Main {
	//nums为选择列表
	static int[] nums = {1, 2, 3, 4, 5};
	//track为路径
	static List<Integer> track = new ArrayList<>();
	static boolean[] vis = new boolean[5];
	
	public static void main(String[] args) {
		backtrack(track);
	}
	
	static void backtrack(List<Integer> track) {
		//终止条件
		if(track.size() == nums.length) {
			System.out.println(track.toString());
			return;
		}
		//遍历决策树
		for (int i = 0; i < nums.length; i++) {
			if(vis[i]) continue;  //排除多余选择
			vis[i] = true;
			track.add(nums[i]);  //做选择
			backtrack(track);    //进入下一层决策树
			vis[i] = false;      //撤销选择
			track.remove(track.size() - 1);
		}
	}
}
