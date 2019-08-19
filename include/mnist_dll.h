#ifndef MNIST_DLL_H
#define MNIST_DLL_H



#ifdef MNIST_DLL_EXPORTS
#define MNIST_DLL_API __declspec(dllexport)
#else
#define MNIST_DLL_API __declspec(dllimport)
#endif


struct layer_struct
{
    uint64_t k;
    uint64_t n;
    uint64_t nr;
    uint64_t nc;
    uint64_t size;
    const float *params;
};



// This function will initialize the network and load the required weights
extern "C" MNIST_DLL_API void init_net(const char *net_name);

// This function will take an grayscale image in std::vector<uint8_t> row major order
// as an input and produce a resulting classification of the image.  The input must be 28*28
extern "C" MNIST_DLL_API uint64_t run_net(uint8_t input[], uint32_t nr, uint32_t nc);

// This function will output a vector of the output layer for the final classification layer
extern "C" MNIST_DLL_API void get_layer_01(struct layer_struct &data, const float* &data_params);

extern "C" MNIST_DLL_API void get_layer_02(struct layer_struct &data, const float* &data_params);

extern "C" MNIST_DLL_API void get_layer_05(struct layer_struct &data, const float* &data_params);

extern "C" MNIST_DLL_API void get_layer_08(struct layer_struct &data, const float* &data_params);

extern "C" MNIST_DLL_API void get_layer_09(struct layer_struct &data, const float* &data_params);

extern "C" MNIST_DLL_API void get_layer_12(struct layer_struct &data, const float* &data_params);

#endif  // MNIST_DLL_H
