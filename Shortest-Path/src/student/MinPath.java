package student;


/** NetId(s): btn28, jr826. Time spent: 2 hours, 45 minutes.
*
* Please be careful in replacing nnnn by netids and hh by hours and
* mm by minutes. Any mistakes cause us to have to fix this manually
* before extracting times, in order to give you the max and median and mean.
* Thanks
* 
* Name(s): Brendon Nguyen, Jason Russo
* What I thought about this assignment: only took 3 hours!!!!!!!!!!!!!!!! 
* super interesting and satisfying to finish
* 
*
*/
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Set;

import graph.Edge;
import graph.Node;

import student.Heap;

/** This class contains Dijkstra's shortest-path algorithm and some other methods. */
public class MinPath {

    /** Return the shortest path from first to last ---or the empty list
     * if a path does not exist.
     * Note: The empty list is NOT "null"; it is a list with 0 elements. */
    public static List<Node> minPath(Node first, Node last) {
        /* TODO Read note A7 FAQs on the course piazza for ALL details. */
        Heap<Node> F= new Heap<Node>(); // As in lecture slides
        HashMap<Node, SFinfo> map = new HashMap<Node, SFinfo>();

        map.put(first, new SFinfo(0, null));
        F.insert(first, 0); 
        
     while (F.size != 0) {
    	 Node f = F.poll();
    	 
    	 if (f.equals(last)) return buildPath(f, map);
    	 
    	 if (f.getExitsSize() == 0) return new LinkedList<Node>();
    	 
    	 for (Edge e : f.getExits()) {
    		 int df = map.get(f).distance;
    		 int dw = df + e.length;
    		 Node w = e.getOther(f);
    		 
    		 if (!map.containsKey(w)) {
    			 F.insert(w, dw); // add w to F
    			 map.put(w, new SFinfo(dw, f)); // setting d[w], bk[w]
    		 }
    		 else if (df + e.length < map.get(w).distance) {
    			 map.put(w, new SFinfo(dw, f));
    			 F.changePriority(w, dw);
    		 }
    	 }
     }	
        return new LinkedList<Node>();
    }


    /** Return the path from the first node to node last.
     *  Precondition: info contains all the necessary information about
     *  the path. */
    public static List<Node> buildPath(Node last, HashMap<Node, SFinfo> info) {
        List<Node> path= new LinkedList<Node>();
        Node p= last;
        // invariant: All the nodes from p's successor to the end are in
        //            path, in reverse order.
        while (p != null) {
            path.add(0, p);
            p= info.get(p).bckPntr;
        }
        return path;
    }

    /** Return the sum of the weights of the edges on path path. */
    public static int pathWeight(List<Node> path) {
        if (path.size() == 0) return 0;
        synchronized(path) {
            Iterator<Node> iter= path.iterator();
            Node p= iter.next();  // First node on path
            int s= 0;
            // invariant: s = sum of weights of edges from start to p
            while (iter.hasNext()) {
                Node q= iter.next();
                s= s + p.getEdge(q).length;
                p= q;
            }
            return s;
        }
    }

    /** An instance contains information about a node: the previous node
     *  on a shortest path from the start node to this node and the distance
     *  of this node from the start node. */
    private static class SFinfo {
        private Node bckPntr; // backpointer on path from start node to this one
        private int distance; // distance from start node to this one

        /** Constructor: an instance with distance d from the start node and
         *  backpointer p.*/
        private SFinfo(int d, Node p) {
            distance= d;     // Distance from start node to this one.
            bckPntr= p;  // Backpointer on the path (null if start node)
        }

        /** return a representation of this instance. */
        public String toString() {
            return "dist " + distance + ", bckptr " + bckPntr;
        }
    }
}
