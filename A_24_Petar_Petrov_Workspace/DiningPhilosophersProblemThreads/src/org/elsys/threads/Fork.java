package org.elsys.threads;

import java.util.Random;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.ReentrantLock;

public class Fork {
	
	private final int id;
	private final ReentrantLock lock = new ReentrantLock();
	private Random random = new Random();

	public Fork(int id) {
		// TODO Auto-generated constructor stub
		this.id = id;
	}
	
	public String toString() {
		return "Fork " + id;
	}
	
	public boolean pickUp(Philosophers who) throws InterruptedException {
		if(lock.tryLock(random.nextInt(1000), TimeUnit.MILLISECONDS)) {
			System.out.println(who + " picked up "  + this.toString());
			return true;
		}
		else {
			return false;
		}
	}
	
	public void putDown(Philosophers who) {
		lock.unlock();
		System.out.println(who + " put down " + this.toString());
	}

}
