#include <jni.h>
#include<iostream>
#include"com_stdying_jni_Complex.h"
using namespace std;

JNIEXPORT void JNICALL Java_com_stdying_jni_Complex_nativeSetName
  (JNIEnv *env, jobject obj, jstring str)
  {
	  /*获取jfieldID以及该字段的初始值*/
	  jfieldID nameFId;
	  /*获取JAVA层该对象实例的类引用，机Complex类的引用*/
	  jclass cls = env->GetObjectClass(obj);
	  /*获取属性句柄*/
	  nameFId = env->GetFieldID(cls,"name","Ljava/lang/String;");
	  if(nameFId == NULL)
	  {
			cout<<"JNI--获取name句柄ID为NULL\n";
	  }

	  /*获取该属性的值*/
	  jstring jStr = (jstring)env->GetObjectField(obj,nameFId);
	  /*转换成char *类型*/
	  const char *c_str = env->GetStringUTFChars(jStr,NULL);
	  string str_name = c_str;
	  cout<<"JNI--The name From java :"<<str_name<<endl;

	  /*释放局部引用*/
	  env->ReleaseStringUTFChars(jStr,c_str);

	  /*设置该字段的值*/
	  env->SetObjectField(obj,nameFId,str);
  }

  /*JNI回调java层的方法*/
JNIEXPORT void JNICALL Java_com_stdying_jni_Complex_doCall
  (JNIEnv *env, jobject obj)
  {
    /*获得java类的实例*/
    jclass cls = env->GetObjectClass(obj);
    /*获得回调方法的句柄*/
    jmethodID callBackId =env->GetMethodID(cls,"jniCall","(Ljava/lang/String;)V");
    
    
    if(callBackId == NULL)
    {
        cout<<"JNI--获取方法句柄失败"<<endl;
    }
    jstring jstr = env->NewStringUTF("In Native");
   
    /*回调java方法，并传入参数*/
    env->CallVoidMethod(obj,callBackId,jstr);
    
    /*删除本地引用*/
    env->DeleteLocalRef(cls);
    env->DeleteLocalRef(jstr);
  }
