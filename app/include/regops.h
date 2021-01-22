#define readl(a) 	(*(volatile unsigned int*)a)
#define writel(v, a) (*(volatile unsigned int*)a = v)
