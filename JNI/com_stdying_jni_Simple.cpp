
#include <jni.h>
#include"com_stdying_jni_Simple.h"

/*
返回字符串
*/
JNIEXPORT jstring JNICALL Java_com_stdying_jni_Simple_getStringJNI
  (JNIEnv *env, jobject obj)
  {
	//直接使用JNI构造jstring对象返回
	jstring str = env->NewStringUTF("Return String");
	return str;
  }
	
/*
构造一位数组，返回二维数组
*/
JNIEXPORT jobjectArray JNICALL Java_com_stdying_jni_Simple_getTwoArray
  (JNIEnv *env, jobject obj, jint size)
  {
	  /*获取一位数组的类引用*/
	  jclass intArr = env->FindClass("[I");
	  /*构建一个intArr类一位数组对象，初始化大小为size*/
	  jobjectArray objArr = env->NewObjectArray(size,intArr,NULL);

	  /*构建size一维数组，并将其引用赋给objArr对象数组*/
	  int i=0;
	  for(i=0;i<size;i++)
	  {
		  /*构建jint型一维数组*/
		  jintArray intArray = env->NewIntArray(size);

		  jint tmp[20];
		  int j=0;
		  /*假设size<20*/
		  for(j=0;j<size;j++)
		  {
			  tmp[j] = i+j;
		  }
		
		/*设置intArray的值*/
		env->SetIntArrayRegion(intArray,0,size,tmp);
		/*对object对象数组复制，即保持对jint一维的引用*/
		env->SetObjectArrayElement(objArr,i,intArray);

		/*删除局部引用,不然随着程序的运行会报错*/
		env->DeleteLocalRef(intArray);
	  }
	return objArr;		
  }
