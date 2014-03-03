package com.stdying.jni;

public class TestMain {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		//testSimple();
		testJniCallJava();
	}

	public static void testSimple(){
		Simple simple = new Simple();
		System.out.println("从JNI得到String："+simple.getStringJNI());
		
		System.out.println("返回二维int数组：");
		int[][] intArr = simple.getTwoArray(3);
		for(int[] i :intArr){
			for(int j:i){
				System.out.print(j+" ");
			}
			System.out.println("\n");
		}
		System.out.println("\n");
	}
	
	public static void testJniCallJava(){
		JniCallJava callJava = new JniCallJava();
		
		callJava.nativeSetName("name set in JNI");
		System.out.println(callJava.getName());
		
		callJava.nativeSetNameStatic("staicname set in JNI");
		System.out.println(JniCallJava.staticName);
		
		System.out.println("--------call method------------");
		callJava.doCall();
		
		System.out.println("********call staic method**********");
		callJava.doCallStatic();
		
		
	}
	
	
	
	static {
		System.out.println(System.getProperty("java.library.path"));
		System.out.println("**************测试************************");
	}


}
