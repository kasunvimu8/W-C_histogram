
public class Queue {
    
    private final int capacity; //100kbits
    private int currentSize; //Kbits
    
    public Queue(int capacity,int currentSize){
        this.capacity = capacity;
        this.currentSize = currentSize;
    }
    
    public int getCapacity(){
        return this.capacity;
    }
    
    public int getCurrentSize(){
        return this.currentSize;
    }
    
    public void setCurrentSize(int size){
        this.currentSize = size;
    }
}
