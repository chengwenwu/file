#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <string.h>
 
#define PUBLICKEY "publicKey.pem"
#define PRIVATEKEY "privateKey.pem"
 
//#define PASS "8888" //口令
 
int main(int argc, char *argv[])
{
    FILE *fp = NULL;
    RSA *publicRsa = NULL;
    RSA *privateRsa = NULL;
    if ((fp = fopen(PUBLICKEY, "r")) == NULL) 
    {
        printf("public key path error\n");
        return -1;
    }   
   
    if ((publicRsa = PEM_read_RSA_PUBKEY(fp, NULL, NULL, NULL)) == NULL) 
    {
        printf("PEM_read_RSA_PUBKEY error\n");
        return -1;
    }
    fclose(fp);
    
    if ((fp = fopen(PRIVATEKEY, "r")) == NULL) 
    {
        printf("private key path error\n");
        return -1;
    }
    //OpenSSL_add_all_algorithms();//密钥有经过口令加密需要这个函数
    if ((privateRsa = PEM_read_RSAPrivateKey(fp, NULL, NULL, NULL/*(char *)PASS*/)) == NULL) 
    {
        printf("PEM_read_RSAPrivateKey error\n");
        return NULL;
    }
    fclose(fp);     
    
    unsigned char *source = (unsigned char *)"123456789";
        
    int rsa_len = RSA_size(publicRsa);
 
    unsigned char *encryptMsg = (unsigned char *)malloc(rsa_len);
    memset(encryptMsg, 0, rsa_len);
        
    int len = rsa_len - 11;
        
    if (RSA_public_encrypt(len, source, encryptMsg, publicRsa, RSA_PKCS1_PADDING) < 0)
        printf("RSA_public_encrypt error\n");
    else 
    {
        rsa_len = RSA_size(privateRsa);
        unsigned char *decryptMsg = (unsigned char *)malloc(rsa_len);
        memset(decryptMsg, 0, rsa_len);
        
        int mun =  RSA_private_decrypt(rsa_len, encryptMsg, decryptMsg, privateRsa, RSA_PKCS1_PADDING);
     
        if ( mun < 0)
            printf("RSA_private_decrypt error\n");
        else
            printf("RSA_private_decrypt %s\n", decryptMsg);
    }   
    
    RSA_free(publicRsa);
    RSA_free(privateRsa);
    return 0;
}