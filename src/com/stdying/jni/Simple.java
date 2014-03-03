package com.stdying.jni;

/**
 * 简单的测试,jni 传递和返回简单参数
 * */
public class Simple {
	/*从JNI获取String*/
	public native String getStringJNI();
	/*从JNI获取二维int数组*/
	public native int[][] getTwoArray(int num);
	
	static {
		System.loadLibrary("simple");
	}
}
