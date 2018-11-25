package com.caesar.auto.threads;

import android.util.Log;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.concurrent.PriorityBlockingQueue;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;

/**
 * 线程池常见函数
 * 1.shutDown()  关闭线程池，不影响已经提交的任务
 * 2.shutDownNow() 关闭线程池，并尝试去终止正在执行的线程
 * 3.allowCoreThreadTimeOut(boolean value) 允许核心线程闲置超时时被回收
 * 4.submit 一般情况下我们使用execute来提交任务，但是有时候可能也会用到submit，使用submit的好处是submit有返回值。
 * 5.beforeExecute() - 任务执行前执行的方法
 * 6.afterExecute() -任务执行结束后执行的方法
 * 7.terminated() -线程池关闭后执行的方法
 */


public class Threads {
    private final static String TAG = "Threads";
    private static Threads threah;
    private ThreadPoolExecutor threadPoolExecutor = null;
    private ExecutorService fixedThreadPool = null;
    private ExecutorService cachedThreadPool = null;
    private ExecutorService singleThreadExecutor = null;
    private ScheduledExecutorService scheduledThreadPool = null;
    private ExecutorService priorityThreadPool = null;

    private Threads() {

    }

    public synchronized static Threads getInstance() {
        if (threah == null) {
            synchronized (Threads.class) {
                if (threah == null) {
                    threah = new Threads();
                }
            }
        }
        return threah;
    }


    public void initThread() {
        //创建基本线程池
        threadPoolExecutor = new ThreadPoolExecutor(3, 5, 1, TimeUnit.SECONDS,
                new LinkedBlockingQueue<Runnable>(100));
        //创建fixed线程池，执行长期的任务，性能好很多
        fixedThreadPool = Executors.newFixedThreadPool(5);
        //创建Cached线程池，执行很多短期异步的小程序或者负载较轻的服务器
        cachedThreadPool = Executors.newCachedThreadPool();
        //创建Single线程池
        singleThreadExecutor = Executors.newSingleThreadExecutor();

        //创建Scheduled线程池,周期性执行任务的场景
        scheduledThreadPool = Executors.newScheduledThreadPool(3);
        //创建自定义线程池(优先级线程)
        priorityThreadPool = new ThreadPoolExecutor(3, 3, 0,
                TimeUnit.SECONDS, new PriorityBlockingQueue<Runnable>());
    }

    public void startBase() {
        for (int i = 0; i < 30; i++) {
            final int finali = i;
            Runnable runnable = new Runnable() {
                @Override
                public void run() {
                    try {
                        Thread.sleep(2000);
                        Log.d(TAG, "run: " + finali);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            };
            threadPoolExecutor.execute(runnable);
        }
    }

    public void startFixed() {
        for (int i = 0; i < 30; i++) {
            final int finali = i;
            Runnable runnable = new Runnable() {
                @Override
                public void run() {
                    try {
                        Thread.sleep(2000);
                        Log.d(TAG, "run: " + finali);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            };
            fixedThreadPool.execute(runnable);
        }
    }

    public void startCached() {
        for (int i = 0; i < 30; i++) {
            final int finali = i;
            Runnable runnable = new Runnable() {
                @Override
                public void run() {
                    try {
                        Thread.sleep(2000);
                        Log.d(TAG, "run: " + finali);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            };
            cachedThreadPool.execute(runnable);
        }
    }

    public void startSingle() {
        for (int i = 0; i < 30; i++) {
            final int finali = i;
            Runnable runnable = new Runnable() {
                @Override
                public void run() {
                    try {
                        Thread.sleep(2000);
                        Log.d(TAG, "run: " + finali);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            };
            singleThreadExecutor.execute(runnable);
        }
    }

    public void startSchedule() {
        Runnable runnable = new Runnable() {
            @Override
            public void run() {
                Log.d(TAG, "This task is delayed to execute");
            }
        };
        scheduledThreadPool.schedule(runnable, 2, TimeUnit.SECONDS);//延迟启动任务
//        //延迟5s后启动，每1s执行一次
//        scheduledThreadPool.scheduleAtFixedRate(runnable, 5, 1, TimeUnit.SECONDS);
//        //启动后第一次延迟5s执行，后面延迟1s执行
//        scheduledThreadPool.scheduleWithFixedDelay(runnable, 5, 1, TimeUnit.SECONDS);
    }

    public void startPriority() {
        for (int i = 0; i < 30; i++) {
            final int priority = i;
            priorityThreadPool.execute(new PriorityRunnable(priority) {
                @Override
                protected void doSomeThing() {
                    Log.d(TAG, "优先级为 " + priority + "  的任务被执行");
                    try {
                        Thread.sleep(2000);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            });
        }
    }

    public void closeThreads() {
        threadPoolExecutor.shutdown();
        fixedThreadPool.shutdown();
        cachedThreadPool.shutdown();
        singleThreadExecutor.shutdown();
        scheduledThreadPool.shutdown();
        priorityThreadPool.shutdown();
    }
}
