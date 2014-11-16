#include <iostream>
#include <cstdlib>
#include <cstring>

class Puntero {
  public:
    Puntero() {
      std::cout << "Constructor defecto" << std::endl;
      this->ptr = 0;
      this->cnt = 1;
    }

    Puntero(void * ptr) {
      std::cout << "Constructor param" << std::endl;
      this->ptr = ptr;
      this->cnt = 1;
    }

    Puntero(const Puntero& o ) {
      this->cnt = o.cnt + 1;
      this->ptr = o.ptr;
      std::cout << "Constructor copia, ref: " << this->cnt << std::endl;
    }

    Puntero& operator=(const Puntero& o ) {

      if ( this->ptr ) free(this->ptr);

      this->ptr = o.ptr;
      this->cnt = o.cnt++;

      std::cout << "Operator Igual ref: " << o.cnt << std::endl;

    }

    ~Puntero() {
      this->cnt--;
      std::cout << "Destructor ref " << this->cnt << std::endl;
      if ( this->cnt == 0 && this->ptr ) {
        std::cout << "free " << std::endl;
        free( this->ptr );
      }
      this->ptr = 0;
    }

    void setValor( unsigned v ) {
      memcpy( this->ptr, &v, sizeof(v) );

    }

    unsigned getValor() {
      return *((unsigned*)this->ptr);
    }

  private:
   void* ptr; 
   mutable unsigned cnt;
};



void otraLlamada( Puntero p0 ) {
  std::cout << "otraLlamada" << std::endl;
  p0.setValor(75);
}

void llamarPuntero( Puntero p0 ) {
  std::cout << "llamarPuntero" << std::endl;
  otraLlamada( p0 );
}



int main(int argc, char** argv) {
  Puntero r;
  Puntero q;
  Puntero p( malloc(sizeof(int)) );

  q = p;
  r = p;

  /*
  q.setValor( 35 );

  llamarPuntero( p );

  std::cout << q.getValor() << std::endl;
  */

}
