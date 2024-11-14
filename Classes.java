
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * The main class where all my programm will be work
 */
public final class UniversityCourseManagementSystem {
    private static List<Course> courselist = new ArrayList<Course>();
    private static ArrayList<UniversityMember> memberlist = new ArrayList<UniversityMember>();

    /**
     * @param args main - main part
     *             fillinitialdata - some data in task
     */
    public static void main(String[] args) {
        fillInitialData();
        int memberid = 7;
        int courseid = 8;
        Scanner in = new Scanner(System.in);
        String command = "a";
        try {
            while (in.hasNextLine()) {
                command = in.nextLine();
                switch (command) {
                    case ("teach"):
                        int teachmid = Integer.valueOf(in.nextLine());              // professor teaches some course */
                        int teachcid = Integer.valueOf(in.nextLine());
                        Professor professorTeach = (Professor) memberlist.get(teachmid - 1);
                        Course courseTeach = courselist.get(teachcid - 1);
                        professorTeach.teach(courseTeach);
                        System.out.println("Professor is successfully assigned to teach this course");
                        break;
                    case ("exempt"):
                        int exemptmid = Integer.valueOf(in.nextLine());            //professor exempts some course
                        int exemptcid = Integer.valueOf(in.nextLine());
                        Professor professorExempt = (Professor) memberlist.get(exemptmid - 1);
                        Course courseExempt = courselist.get(exemptcid - 1);
                        professorExempt.exempt(courseExempt);
                        System.out.println("Professor is exempted");
                        break;
                    case ("drop"):
                        int dropmid = Integer.valueOf(in.nextLine());           //student drops one course
                        int dropcid = Integer.valueOf(in.nextLine());
                        Student studentDrop = (Student) memberlist.get(dropmid - 1);
                        Course courseDrop = courselist.get(dropcid - 1);
                        studentDrop.drop(courseDrop);
                        System.out.println("Dropped successfully");
                        break;
                    case ("enroll"):
                        int enrollmid = Integer.valueOf(in.nextLine());         // student enrolls one course
                        int enrollcid = Integer.valueOf(in.nextLine());
                        Student studentEnroll = (Student) memberlist.get(enrollmid - 1);
                        Course courseEnroll = courselist.get(enrollcid - 1);
                        studentEnroll.enroll(courseEnroll);
                        System.out.println("Enrolled successfully");
                        break;
                    case ("professor"):
                        String pmn = in.nextLine();                         //create a new professor
                        boolean onlyEnglishProfessor = pmn.matches("^[a-zA-Z]+$");
                        if (!onlyEnglishProfessor || pmn.equals("course") || pmn.equals("professor")
                                || pmn.equals("student")
                                || pmn.equals("enroll") || pmn.equals("teach") || pmn.equals("drop")
                                || pmn.equals("exempt")) {
                            System.out.println("Wrong inputs");
                            System.exit(0);
                        }
                        Professor professor = new Professor(memberid, pmn);
                        memberlist.add(professor);
                        memberid++;
                        System.out.println("Added successfully");
                        break;
                    case ("student"):
                        String smn = in.nextLine();                     //create a new student
                        boolean onlyEnglishStudent = smn.matches("^[a-zA-Z]+$");
                        if (!onlyEnglishStudent || smn.equals("course") || smn.equals("professor")
                                || smn.equals("student") || smn.equals("enroll") || smn.equals("teach")
                                || smn.equals("drop") || smn.equals("exempt")) {
                            System.out.println("Wrong inputs");
                            System.exit(0);
                        }
                        Student student = new Student(memberid, smn);
                        memberlist.add(student);
                        memberid++;
                        System.out.println("Added successfully");
                        break;
                    case ("course"):
                        String cn = in.nextLine();                      //create a new course
                        String cl1 = in.nextLine();
                        if (cl1.equals("bachelor") || cl1.equals("BACHELOR")) {
                            Course c = new Course(cn, CourseLevel.BACHELOR);
                            courseid++;
                            if (courselist.contains(c)) {
                                System.out.println("Course exists");
                                System.exit(0);
                            }
                            courselist.add(c);
                        } else if (cl1.equals("master") || cl1.equals("MASTER")) {
                            Course c = new Course(cn, CourseLevel.MASTER);
                            if (courselist.contains(c)) {
                                System.out.println("Course exists");
                                System.exit(0);
                            }
                            courseid++;
                            courselist.add(c);
                        } else {
                            System.out.println("Wrong inputs");
                            System.exit(0);
                        }
                        System.out.println("Added successfully");
                        courseid++;
                        break;
                    default:
                        System.out.println("Wrong inputs");
                        System.exit(0);
                        break;
                }
            }
        } catch (Exception e) {
            System.out.println("Invalid inputs");
            System.exit(0);
        }
    }

    /**
     * In task we have some given data,
     * its scanning here
     */
    public static void fillInitialData() {
        int id = 1;
        Course c1 = new Course("java_beginner", CourseLevel.BACHELOR);
        Course c2 = new Course("java_intermediate", CourseLevel.BACHELOR);
        Course c3 = new Course("python_basics", CourseLevel.BACHELOR);
        Course c4 = new Course("algorithms", CourseLevel.MASTER);
        Course c5 = new Course("advanced_programming", CourseLevel.MASTER);
        Course c6 = new Course("mathematical_analysis", CourseLevel.MASTER);
        Course c7 = new Course("computer_vision", CourseLevel.MASTER);
        courselist.add(c1);
        courselist.add(c2);
        courselist.add(c3);
        courselist.add(c4);
        courselist.add(c5);
        courselist.add(c6);
        courselist.add(c7);
        Student s1 = new Student(id, "Alice");
        id++;
        Student s2 = new Student(id, "Bob");
        id++;
        Student s3 = new Student(id, "Alex");
        id++;
        s1.enroll(c1); s1.enroll(c2); s1.enroll(c3);
        s2.enroll(c1); s2.enroll(c4);
        s3.enroll(c5);
        memberlist.add(s1);
        memberlist.add(s2);
        memberlist.add(s3);
        Professor p1 = new Professor(id, "Ali");
        id++;
        Professor p2 = new Professor(id, "Ahmed");
        id++;
        Professor p3 = new Professor(id, "Andrey");
        p1.teach(c1); p1.teach(c2);
        p2.teach(c3); p2.teach(c4);
        p3.teach(c5);
        memberlist.add(p1);
        memberlist.add(p2);
        memberlist.add(p3);
    }
}


/**
 * interface with two methods for class student
 */
interface Enrollable {
    public boolean drop(Course course);

    public boolean enroll(Course course);
}

abstract class UniversityMember {
    private static int numberOfMembers;
    private int memberid;
    private String memberName;
    public  UniversityMember(int memberid, String memberName) {
        this.memberid = memberid;
        this.memberName = memberName;
    }

    public String getMemberName() {
        return memberName;
    }
}
/**
 * Enum representing the level of a course, whether it's bachelor or master level.
 */
enum CourseLevel {
    BACHELOR,
    MASTER
}
/**
 * Represents a course in the university.
 */
class Course {
    private final int capAcity = 3;
    private static int numberOfCourses;
    private int courseid;
    private String courseName;
    private List<Student> enrolledStudents;
    private CourseLevel courseLevel;
    public Course(String courseName, CourseLevel courseLevel) {
        this.courseName = courseName;
        this.courseLevel = courseLevel;
    }
    public List<Student> getEnrolledStudents() {
        return enrolledStudents;
    }
    public String getCourseName() {
        return courseName;
    }

    public boolean isFull() { //check if course has places for new students
        return enrolledStudents.size() > capAcity;
    }
    public int getCourseID() {
        return courseid;
    }
}
/**
 * Represents a professor in the university.
 */
class Professor extends UniversityMember {
    private final int maxLoad = 2;
    private List<Course> assignedCourses = new ArrayList<>();

    public Professor(int memberid, String memberName) {
        super(memberid, memberName);
    }

    /**
     * @param course
     * @return  can professor teach another one course of he's busy
     */
    public boolean teach(Course course) { //teach someone
        if (assignedCourses.contains(course)) {
            System.out.println("Professor is already teaching this course");
            System.exit(0);
        }
        if (assignedCourses.size() < maxLoad) {
            assignedCourses.add(course);
        } else {
            System.out.println("Professor's load is complete");
            System.exit(0);
        }
        return true;
    }

    /**
     * @param course
     * @return can professor exempt one more course or not
     */
    public boolean exempt(Course course) { //leaving this course of stupid students
        if (!assignedCourses.contains(course)) {
            System.out.println("Professor is not teaching this course");
            System.exit(0);
            return false;
        }
        assignedCourses.remove(course);
        return true;
    }


}
/**
 * Represents a student in the university.
 */
class Student extends UniversityMember implements Enrollable {
    private static final int MAX_ENROLLMENT = 3;
    private List<Course> enrolledCourses = new ArrayList<>();
    public Student(int memberid, String memberName) {
        super(memberid, memberName);
    }

    @Override
    public String getMemberName() {
        return super.getMemberName();
    }

    /**
     * @param course
     * @return can student drop from this course or not
     */
    @Override
    public boolean drop(Course course) { //see ya on retake
        if (!enrolledCourses.contains(course)) {
            System.out.println("Student is not enrolled in this course");
            System.exit(0);
            return false;
        }
        enrolledCourses.remove(course);
        return true;
    }

    /**
     * @param course
     * @return can student enroll this course or not
     */
    @Override
    public boolean enroll(Course course) { //give student a new course
        if (enrolledCourses.contains(course)) {
            System.out.println("Student is already enrolled in this course");
            System.exit(0);
        } else if (enrolledCourses.size() >= MAX_ENROLLMENT) {
                System.out.println("Maximum enrollment is reached for the student");
                System.exit(0);
        } else {
            enrolledCourses.add(course);
        }
        return true;
    }
}

