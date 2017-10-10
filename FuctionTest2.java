class FuctionTest2{
	public static void main(String[] args){
		
		int[] max = {23,45,234,57,43,52,2,7,23,5,32,52,73,7,456,322,677,2,34,6};
		int[] line = {1,2,3,4,5,6,7,8,9};
		//int x = maxArr(max);
		//System.out.println("数组中的最大值是："+x);
		
		GetLineArr(line);
		System.out.println("---------------");
		GetLineArr(max);
		
	}
	
	public static int maxArr(int[] arr){
		int max = 0;
		for(int i=0;i<arr.length;i++){
			if(i == 0){
				max = arr[i];
			}
			else{
				if(arr[i]>=max){
					max = arr[i];
				}
			}
		}
		
		return max;
	}
	
	
	//数组元素逆序
	public static void GetLineArr(int[] arr){
		int start = 0;
		int end = arr.length - 1;
		
		for(int i = 0;i<arr.length/2;i++){
			int tmp = 0;
			tmp = arr[start+i];
			arr[start+i] = arr[end - i];
			arr[end - i] = tmp;
		}
		
		for(int j = 0;j<arr.length;j++){
			if(j == arr.length - 1){
				System.out.println(arr[j]);
			}
			else{
				System.out.print(arr[j]+", ");
			}
		}
		
	}
}