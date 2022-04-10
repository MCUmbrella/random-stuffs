import java.util.*;
public class s
{
    enum Sex
    {
        MALE,
        FEMALE
    }
    
    static Sex parseSex(String s)
    {
        switch(s.toLowerCase())
        {
            case "male":
            case "man":
            case "m":
            case "男":
                return Sex.MALE;
            case "female":
            case "woman":
            case "f":
            case "女":
                return Sex.FEMALE;
            default:
                throw new IllegalArgumentException("Not a valid sex type");
        }
    }
    
    public static void main(String args[])
    {

        class Student
        {
            private String name;
            private Sex sex;
            private int age;
            
            public Student setName(String name){this.name=name;return this;}
            public Student setSex(Sex sex){this.sex=sex;return this;}
            public Student setAge(int age){this.age=age;return this;}
            
            public String getName(){return name;}
            public Sex getSex(){return sex;}
            public int getAge(){return age;}
            
            @Override
            public String toString()
            {
                return this.getName()+", "+(this.getSex()==Sex.MALE?"男":"女")+", "+this.getAge()+"岁";
            }
        }
        
        Scanner sc=new Scanner(System.in);
        Student st=new Student();
        System.out.print("Enter name: ");
        st.setName(sc.nextLine());
        System.out.print("Enter sex: ");
        st.setSex(parseSex(sc.nextLine()));
        System.out.print("Enter age: ");
        st.setAge(Integer.parseUnsignedInt(sc.nextLine()));
        System.out.println(st);
    }
}
