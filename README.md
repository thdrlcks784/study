## 의존성
   * Volley  
      네트워크 연결에 ```Volley @1.1.1```를 사용
      Volley 사용을 위해 Gradle에 아래의 의존성 문장 추가
      ```
      implementation 'com.android.volley:volley:1.1.1'
      ```

      예시  
      ```
      dependencies {
               implementation fileTree(dir: "libs", include: ["*.jar"])
               implementation 'com.android.support:appcompat-v7:28.0.0'
               implementation 'com.android.support.constraint:constraint-layout:1.1.3'
               implementation 'com.android.volley:volley:1.1.1'   //Volley 사용을 위한 의존성 추가
               testImplementation 'junit:junit:4.12'
               androidTestImplementation 'com.android.support.test:runner:1.0.2'
               androidTestImplementation 'com.android.support.test.espresso:espresso-core:3.0.2'
           }
      ```
## 기여하기
