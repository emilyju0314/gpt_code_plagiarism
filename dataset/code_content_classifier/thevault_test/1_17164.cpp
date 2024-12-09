TEST_F(ScopedJavaRefTest, Conversions) {
  JNIEnv* env = AttachCurrentThread();
  ScopedJavaLocalRef<jstring> str = ConvertUTF8ToJavaString(env, "string");
  ScopedJavaGlobalRef<jstring> global(str);

  // Contextual conversions to bool should be allowed.
  EXPECT_TRUE(str);
  EXPECT_FALSE(JavaRef<jobject>());

  // All the types should convert from nullptr, even JavaRef.
  {
    JavaRef<jstring> null_ref(nullptr);
    EXPECT_FALSE(null_ref);
    ScopedJavaLocalRef<jobject> null_local(nullptr);
    EXPECT_FALSE(null_local);
    ScopedJavaGlobalRef<jarray> null_global(nullptr);
    EXPECT_FALSE(null_global);
  }

  // Local and global refs should {copy,move}-{construct,assign}.
  // Moves should leave the source as null.
  {
    ScopedJavaLocalRef<jstring> str2(str);
    EXPECT_SAME_OBJECT(str2, str);
    ScopedJavaLocalRef<jstring> str3(std::move(str2));
    EXPECT_SAME_OBJECT(str3, str);
    EXPECT_FALSE(str2);
    ScopedJavaLocalRef<jstring> str4;
    str4 = str;
    EXPECT_SAME_OBJECT(str4, str);
    ScopedJavaLocalRef<jstring> str5;
    str5 = std::move(str4);
    EXPECT_SAME_OBJECT(str5, str);
    EXPECT_FALSE(str4);
  }
  {
    ScopedJavaGlobalRef<jstring> str2(global);
    EXPECT_SAME_OBJECT(str2, str);
    ScopedJavaGlobalRef<jstring> str3(std::move(str2));
    EXPECT_SAME_OBJECT(str3, str);
    EXPECT_FALSE(str2);
    ScopedJavaGlobalRef<jstring> str4;
    str4 = global;
    EXPECT_SAME_OBJECT(str4, str);
    ScopedJavaGlobalRef<jstring> str5;
    str5 = std::move(str4);
    EXPECT_SAME_OBJECT(str5, str);
    EXPECT_FALSE(str4);
  }

  // As above but going from jstring to jobject.
  {
    ScopedJavaLocalRef<jobject> obj2(str);
    EXPECT_SAME_OBJECT(obj2, str);
    ScopedJavaLocalRef<jobject> obj3(std::move(obj2));
    EXPECT_SAME_OBJECT(obj3, str);
    EXPECT_FALSE(obj2);
    ScopedJavaLocalRef<jobject> obj4;
    obj4 = str;
    EXPECT_SAME_OBJECT(obj4, str);
    ScopedJavaLocalRef<jobject> obj5;
    obj5 = std::move(obj4);
    EXPECT_SAME_OBJECT(obj5, str);
    EXPECT_FALSE(obj4);
  }
  {
    ScopedJavaGlobalRef<jobject> obj2(global);
    EXPECT_SAME_OBJECT(obj2, str);
    ScopedJavaGlobalRef<jobject> obj3(std::move(obj2));
    EXPECT_SAME_OBJECT(obj3, str);
    EXPECT_FALSE(obj2);
    ScopedJavaGlobalRef<jobject> obj4;
    obj4 = global;
    EXPECT_SAME_OBJECT(obj4, str);
    ScopedJavaGlobalRef<jobject> obj5;
    obj5 = std::move(obj4);
    EXPECT_SAME_OBJECT(obj5, str);
    EXPECT_FALSE(obj4);
  }

  // Explicit copy construction or assignment between global<->local is allowed,
  // but not implicit conversions.
  {
    ScopedJavaLocalRef<jstring> new_local(global);
    EXPECT_SAME_OBJECT(new_local, str);
    new_local = global;
    EXPECT_SAME_OBJECT(new_local, str);
    ScopedJavaGlobalRef<jstring> new_global(str);
    EXPECT_SAME_OBJECT(new_global, str);
    new_global = str;
    EXPECT_SAME_OBJECT(new_local, str);
    static_assert(!std::is_convertible<ScopedJavaLocalRef<jobject>,
                                       ScopedJavaGlobalRef<jobject>>::value,
                  "");
    static_assert(!std::is_convertible<ScopedJavaGlobalRef<jobject>,
                                       ScopedJavaLocalRef<jobject>>::value,
                  "");
  }

  // Converting between local/global while also converting to jobject also works
  // because JavaRef<jobject> is the base class.
  {
    ScopedJavaGlobalRef<jobject> global_obj(str);
    ScopedJavaLocalRef<jobject> local_obj(global);
    const JavaRef<jobject>& obj_ref1(str);
    const JavaRef<jobject>& obj_ref2(global);
    EXPECT_SAME_OBJECT(obj_ref1, obj_ref2);
    EXPECT_SAME_OBJECT(global_obj, obj_ref2);
  }
  global.Reset(str);
  const JavaRef<jstring>& str_ref = str;
  EXPECT_EQ("string", ConvertJavaStringToUTF8(str_ref));
  str.Reset();
}