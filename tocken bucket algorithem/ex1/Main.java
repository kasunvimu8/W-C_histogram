
import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;


public class Main extends Thread {
    
    public TokenBucket bucket;
    
    public Main(TokenBucket bucket){
        this.bucket = bucket; 
    }
    
    @Override
    public void run(){
        int newSize;
        while(true){
            newSize = bucket.getCurrentSize() + bucket.getTokenRate();
            if(newSize>bucket.getCapacity()) newSize = bucket.getCapacity();
            bucket.setCurrentSize(newSize);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException ex) {
                Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
    
    public static int createPacket(){
        Random rand = new Random();
        int tmp = rand.nextInt(20);
        return tmp;
    }
    
    public static void main(String [] args) throws InterruptedException{
        //while(true) System.out.println(createPacket());
        TokenBucket tb = new TokenBucket(100,10,2,50);
        Main t = new Main(tb);
        
        
        t.start();
        int packetCount,sentPacket = 0,distroyPacket = 0 ,tmp;
        System.out.println("Bucket Capacity : " + tb.getCapacity() + " bits");
        System.out.println("Token Rate      : " + tb.getTokenRate() + " b/s");
        System.out.println("Token Size      : " + tb.getTokenSize() + " bits");
       
        while(true) {
            //System.out.println(tb.getCurrentSize());
            packetCount = createPacket(); 
            tmp = tb.getTokenCount();
            System.out.println(" tokens --> "+ tmp + " Data packets --> " + packetCount + " Sent packets --> " 
                    + sentPacket + " Distroy packets --> " + distroyPacket);
            if(packetCount >= tmp){
                distroyPacket += (packetCount - tmp);
                sentPacket += tmp;
                tb.setCurrentSize(0);
            }else{
                sentPacket += packetCount;
                tmp = tmp - packetCount;
                tb.setCurrentSize(tmp * tb.getTokenSize());
            }
            
            Thread.sleep(1000);
        }
        
    }
    
}
