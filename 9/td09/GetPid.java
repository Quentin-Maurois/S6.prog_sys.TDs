public class GetPid {
    public static native long getPid();

    static {
        System.out.print("Loading getPid native library...");
        System.loadLibrary("HelloWorld");
        System.out.println(" done.");
    }

    public static void main(String args[]) {
        System.out.println("Pid : " + getPid());

    }
}
