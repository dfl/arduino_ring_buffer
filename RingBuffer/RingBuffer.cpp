#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "RingBuffer.h"

RingBuffer::RingBuffer( int size ) {
  _size = size;
  buffer.init(sizeof(int) * size );
}

void RingBuffer::add( int value ) {
  buffer.putInt(value);
  calc_mean();
}

int RingBuffer::size() {
  return buffer.getSize();
}

void RingBuffer::isFull {
  return buffer.getSize() == buffer.getCapacity();
}

void RingBuffer::mean() {
  return _mean;
}

void RingBuffer::calc_mean() {
  int size = buffer.getSize();
  for (int i=0; i<size; i++) {
    sum += (double)buffer.get(i);
  }
  _mean = sum / size;
}

void RingBuffer::variance() {
  int sum = 0;
  int size = this.size();
  for(int i=0; i <= size; i++) {
    sum +=  buffer(i) - _mean;
  }
  return sum / (size-1); // what about int vs float?
}

void RingBuffer::std() {
  sqrtf( variance() ); // what about int vs float
}

  // public double max() {
  //   double val;
  //   max = 0.0;
  //   for (int i=0; i<buffer.size(); i++) {
  //     val = (double)buffer.get(i);
  //     if ( val > max ) {
  //       max = val;
  //     }
  //   }
  //   return max;
  // }

  // public double get(int idx){
  //   return buffer.get(idx);
  // }

  // public void clear(){
  //   buffer.clear();
  // }

  // public double min() {
  //   double val;
  //   min = 1.0;
  //   for (int i=0; i<buffer.size(); i++) {
  //     val = (double)buffer.get(i);
  //     if ( val < min ) {
  //       min = val;
  //     }
  //   }
  //   return min;
  // }

  // public double[] toArray() {
  //   // http://stackoverflow.com/questions/9572795/convert-list-to-array-in-java
  //   // return buffer.stream().toArray(double[]::new);
  //   double[] output = new double[ this.size() ];
  //   for(int i=0; i< this.size(); i++ ){
  //     output[i] = buffer.get(i);
  //   }
  //   return output;
  // }

  // public void print() {
  //   System.out.print(" buffer: [");
  //   for (int i=0; i<buffer.size (); i++) {
  //     System.out.print(buffer.get(i) + ", ");
  //   }
  //   System.out.print("]\n");
  // }

