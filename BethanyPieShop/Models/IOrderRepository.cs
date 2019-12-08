namespace BethanyPieShop.Models
{
    public interface IOrderRepository
    {
        void createOrder(Order order);
    }
}