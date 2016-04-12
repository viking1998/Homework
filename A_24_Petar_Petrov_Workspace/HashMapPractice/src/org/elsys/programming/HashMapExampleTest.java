package org.elsys.programming;

import org.junit.Before;
import org.junit.Test;

import junit.framework.TestCase;

public class HashMapExampleTest extends TestCase {
	
	private HashMapImpl map;
	
	@Before
	public void setUp() {
		map = new HashMapImpl();
	}

	@Test
	public void testCanAddElements() {
		map.add("key", 5);
		
		assertEquals(5, map.get("key"));
	}
	
	@Test
	public void testCanAddMultipleElement() {
		map.add("key1", 5);
		map.add("key1", 6);
		
		assertEquals(6, map.get("key1"));
	}

	@Test
	public void testHashMapTestResize() {
		
		for(int i = 0; i < 20; i++) {
			map.add("key" + i, i);
		}
		
		for(int i = 0; i < 20; i++) {
			System.out.println(i);
			assertEquals(map.get("key" + i), i);
		}
	}
}
