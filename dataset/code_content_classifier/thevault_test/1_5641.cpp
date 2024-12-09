void InputProduct(int Count)
{
    NumberOfProductsCounter();
    for(int i = 0; i < Count; i++)
    {
        CreateProduct();
    }
    NumberOfProductsCounter();
}