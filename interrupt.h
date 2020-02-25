#define INTERRUPT_VBLANK (1 << 0)
#define INTERRUPT_LCDC (1 << 1)
#define INTERRUPT_TIMER (1 << 2)
#define INTERRUPT_STC (1 << 3)
#define INTERRUPT_IO (1 << 4)

struct interrupt {
    unsigned char master;
    unsigned char enable;
    unsigned char flags;
} extern interrupt;

void INTERRUPTSTEP(void);

void interrupt_vblank(void);
void interrupt_lcdc(void);
void interrupt_timer(void);
void interrupt_stc(void);
void interrupt_io(void);

void breakInterrupt(void);