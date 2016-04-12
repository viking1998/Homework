package org.elsys.threads;

import java.util.ArrayList;

public class Application {
	
	public static final int COUNT = 5;
	public static final int DINING_TIME = 10_000;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArrayList<Fork> forks = new ArrayList<>();
		for(int i=0; i < COUNT; i++) {
			forks.add(new Fork(i));
		}
		
		ArrayList<Philosophers> philosophers = new ArrayList<>();
		for(int i=0; i < COUNT; i++) {
			Philosophers p = new Philosophers(i, forks.get(i), forks.get((i + 1) % COUNT));
			philosophers.add(p);
		}
		
		for(Philosophers p : philosophers) {
			p.start();
		}
		
		try {
			Thread.sleep(DINING_TIME);
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		
		for(Philosophers p : philosophers) {
			p.finishDining();
		}
		
		for(Philosophers p : philosophers) {
			try {
				p.join();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}

}
