
#include <jni.h>
#include"com_stdying_jni_Simple.h"

/*
�����ַ���
*/
JNIEXPORT jstring JNICALL Java_com_stdying_jni_Simple_getStringJNI
  (JNIEnv *env, jobject obj)
  {
	//ֱ��ʹ��JNI����jstring���󷵻�
	jstring str = env->NewStringUTF("Return String");
	return str;
  }
	
/*
����һλ���飬���ض�ά����
*/
JNIEXPORT jobjectArray JNICALL Java_com_stdying_jni_Simple_getTwoArray
  (JNIEnv *env, jobject obj, jint size)
  {
	  /*��ȡһλ�����������*/
	  jclass intArr = env->FindClass("[I");
	  /*����һ��intArr��һλ������󣬳�ʼ����СΪsize*/
	  jobjectArray objArr = env->NewObjectArray(size,intArr,NULL);

	  /*����sizeһά���飬���������ø���objArr��������*/
	  int i=0;
	  for(i=0;i<size;i++)
	  {
		  /*����jint��һά����*/
		  jintArray intArray = env->NewIntArray(size);

		  jint tmp[20];
		  int j=0;
		  /*����size<20*/
		  for(j=0;j<size;j++)
		  {
			  tmp[j] = i+j;
		  }
		
		/*����intArray��ֵ*/
		env->SetIntArrayRegion(intArray,0,size,tmp);
		/*��object�������鸴�ƣ������ֶ�jintһά������*/
		env->SetObjectArrayElement(objArr,i,intArray);

		/*ɾ���ֲ�����,��Ȼ���ų�������лᱨ��*/
		env->DeleteLocalRef(intArray);
	  }
	return objArr;		
  }
