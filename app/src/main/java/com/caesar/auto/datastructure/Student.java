package com.caesar.auto.datastructure;

//同姓名同年龄的学生视为同一个学生。按照学生的年龄排序。
public class Student implements Comparable {
    private int age;
    private String name;

    Student(String name, int age) {
        this.age = age;
        this.name = name;
    }

    public int compareTo(Object obj) {

        Student stu = (Student) obj;

        int num = new Integer(this.age).compareTo(new Integer(stu.age));

        return num == 0 ? this.name.compareTo(stu.name) : num;

        /*
        if(this.age>stu.age)
            return 1;
        if(this.age==stu.age)
            return this.name.compareTo(stu.name);
        return -1;
        */
        /**/
    }

    public int getAge() {
        return age;
    }

    public String toString() {
        return name + "::" + age;
    }
}