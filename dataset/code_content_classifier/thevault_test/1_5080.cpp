void ts::GetProcessMetrics(ProcessMetrics& metrics)
{
    metrics.cpu_time = 0;
    metrics.vmem_size = 0;

#if defined(TS_WINDOWS)

    // Windows implementation

    // Get a handle to the current process
    ::HANDLE proc(::GetCurrentProcess());

    // Get process CPU time
    ::FILETIME creation_time, exit_time, kernel_time, user_time;
    if (::GetProcessTimes(proc, &creation_time, &exit_time, &kernel_time, &user_time) == 0) {
        throw ts::Exception(u"GetProcessTimes error", ::GetLastError());
    }
    metrics.cpu_time = ts::Time::Win32FileTimeToMilliSecond(kernel_time) + ts::Time::Win32FileTimeToMilliSecond(user_time);

    // Get virtual memory size
    ::PROCESS_MEMORY_COUNTERS_EX mem_counters;
    if (::GetProcessMemoryInfo(proc, (::PROCESS_MEMORY_COUNTERS*)&mem_counters, sizeof(mem_counters)) == 0) {
        throw ts::Exception(u"GetProcessMemoryInfo error", ::GetLastError());
    }
    metrics.vmem_size = mem_counters.PrivateUsage;

#elif defined(TS_LINUX)

    // Linux implementation.

    //  Definition of data available from /proc/<pid>/stat
    //  See man page for proc(5) for more details.
    struct ProcessStatus {
        int           pid;         // The process id.
        char          state;       // One char from "RSDZTW"
        int           ppid;        // The PID of the parent.
        int           pgrp;        // The process group ID of the process.
        int           session;     // The session ID of the process.
        int           tty_nr;      // The tty the process uses.
        int           tpgid;       // Process group ID which owns the tty
        unsigned long flags;       // The flags of the process.
        unsigned long minflt;      // Minor faults the process made
        unsigned long cminflt;     // Minor faults the process's children made
        unsigned long majflt;      // Major faults the process made
        unsigned long cmajflt;     // Major faults the process's children made
        unsigned long utime;       // Number of jiffies in user mode
        unsigned long stime;       // Number of jiffies in kernel mode
        long          cutime;      // Jiffies process's children in user mode
        long          cstime;      // Jiffies process's children in kernel mode
        long          priority;    // Standard nice value, plus fifteen.
        long          nice;        // Nice value, from 19 (nicest) to -19 (not nice)
        long          itrealvalue; // Jiffies before the next SIGALRM
        unsigned long starttime;   // Jiffies the process started after system boot
        unsigned long vsize;       // Virtual memory size in bytes.
        long          rss;         // Resident Set Size
        unsigned long rlim;        // Current limit in bytes on the rss
        unsigned long startcode;   // Address above which program text can run.
        unsigned long endcode;     // Address below which program text can run.
        unsigned long startstack;  // Address of the start of the stack
        unsigned long kstkesp;     // Current value of esp (stack pointer)
        unsigned long kstkeip;     // Current EIP (instruction pointer).
        unsigned long signal;      // Bitmap of pending signals (usually 0).
        unsigned long blocked;     // Bitmap of blocked signals
        unsigned long sigignore;   // Bitmap of ignored signals.
        unsigned long sigcatch;    // Bitmap of catched signals.
        unsigned long wchan;       // "Channel" in which the process is waiting
        unsigned long nswap;       // Number of pages swapped - not maintained.
        unsigned long cnswap;      // Cumulative nswap for child processes.
        int           exit_signal; // Signal to be sent to parent when we die.
        int           processor;   // CPU number last executed on.
    };

    static const char filename[] = "/proc/self/stat";
    FILE* fp = fopen(filename, "r");
    if (fp == nullptr) {
        throw ts::Exception(UString::Format(u"error opening %s", {filename}), errno);
    }

    ProcessStatus ps;
    int expected = 37;
    int count = fscanf(fp,
        "%d %*s %c %d %d %d %d %d %lu %lu %lu %lu %lu %lu %lu "
        "%ld %ld %ld %ld %*d %ld %lu %lu %ld %lu %lu %lu %lu "
        "%lu %lu %lu %lu %lu %lu %lu %lu %lu %d %d",
        &ps.pid, &ps.state, &ps.ppid, &ps.pgrp, &ps.session,
        &ps.tty_nr, &ps.tpgid, &ps.flags, &ps.minflt,
        &ps.cminflt, &ps.majflt, &ps.cmajflt, &ps.utime,
        &ps.stime, &ps.cutime, &ps.cstime, &ps.priority,
        &ps.nice, &ps.itrealvalue, &ps.starttime, &ps.vsize,
        &ps.rss, &ps.rlim, &ps.startcode, &ps.endcode,
        &ps.startstack, &ps.kstkesp, &ps.kstkeip, &ps.signal,
        &ps.blocked, &ps.sigignore, &ps.sigcatch, &ps.wchan,
        &ps.nswap, &ps.cnswap, &ps.exit_signal, &ps.processor);
    fclose(fp);

    if (count != expected) {
        throw ts::Exception(UString::Format(u"error reading %s, got %d values, expected %d", {filename, count, expected}));
    }

    // Get virtual memory size
    metrics.vmem_size = ps.vsize;

    // Evaluate CPU time
    unsigned long jps = sysconf(_SC_CLK_TCK);   // jiffies per second
    unsigned long jiffies = ps.utime + ps.stime; // CPU time in jiffies
    metrics.cpu_time = (MilliSecond(jiffies) * 1000) / jps;

#elif defined(TS_MAC)

    // MacOS implementation.
    // First, get the virtual memory size using task_info (mach kernel).
    ::mach_task_basic_info_data_t taskinfo;
    TS_ZERO(taskinfo);
    ::mach_msg_type_number_t count = MACH_TASK_BASIC_INFO_COUNT;
    const ::kern_return_t status1 = ::task_info(::mach_task_self(), MACH_TASK_BASIC_INFO, ::task_info_t(&taskinfo), &count);
    if (status1 != KERN_SUCCESS) {
        throw ts::Exception(u"task_info error");
    }
    metrics.vmem_size = taskinfo.virtual_size;

    // Then get CPU time using getrusage.
    ::rusage usage;
    const int status2 = ::getrusage(RUSAGE_SELF, &usage);
    if (status2 < 0) {
        throw ts::Exception(u"getrusage error");
    }

    // Add system time and user time, in milliseconds.
    metrics.cpu_time =
        MilliSecond(usage.ru_stime.tv_sec) * MilliSecPerSec +
        MilliSecond(usage.ru_stime.tv_usec) / MicroSecPerMilliSec +
        MilliSecond(usage.ru_utime.tv_sec) * MilliSecPerSec +
        MilliSecond(usage.ru_utime.tv_usec) / MicroSecPerMilliSec;

#else
#error "ts::GetProcessMetrics not implemented on this system"
#endif
}