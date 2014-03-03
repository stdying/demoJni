package com.stdying.jni;

/**
 * 在native操作java层数据
 * 在JNI中访问类成员变量和类的方法
 * 
 * @version 1.0 2014-1-16
 * @author liulili
 * */
public class JniCallJava {
	/***************************JNI 访问变量****************************************/
	
	/*在JNI里设置非静态变量*/
	public native void nativeSetName(String str);
	
	public String getName(){
		return this.name;
	}
	
	/*在JNI里设置静态变量*/
	public native void nativeSetNameStatic(String str);
	
	/*局部变量*/
	private String name ="name in java";
	
	/*静态变量*/
	public static String staticName ="static name in java";
	
	/*************************JNI 调用方法*****************************/
	
	/*在JNI中访问类的方法*/
	
	/*在native中调用jniCall*/
	public native void doCall();
	public void jniCall(String msg){
		System.out.println("The method is defiend in java.It's called in "+msg);
		
	}
	
	/*在native中调用静态方法*/
	public native void doCallStatic();
	public static void  jniCallStatic(String msg){
		System.out.println("The static method is defiend in java.It's called in "+msg);
		
	}
	
	static {
		System.loadLibrary("JniCallJava");
	} 

}
