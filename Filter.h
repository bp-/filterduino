class Filter
{
  public:
  
  float G, a1, a2, b0, b1, b2;
  float u[3], y[3];
  
  Filter();
  float update(float u0);

};
