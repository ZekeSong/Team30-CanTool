class ArgsDemo{
	public int sum(int a,int b){
		int result = (a+b);
		return result;
	}
}

class ArgsDemo2{
	public void Print(ArgsDemo s){
		int x=10;
		int y=20;
		int result = 0;
		result = s.sum(x,y);
		System.out.println(result);
	}
}



class ArgsTest{
	public static void main(String[] args){ 
		ArgsDemo2 result = new ArgsDemo2();
		
		ArgsDemo t = new ArgsDemo();
		result.Print(t);
		
	}
}