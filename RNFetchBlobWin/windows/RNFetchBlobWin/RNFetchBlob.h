#pragma once
#include "NativeModules.h"
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Security.Cryptography.h>
#include <winrt/Windows.Security.Cryptography.Core.h>

namespace Cryptography = winrt::Windows::Security::Cryptography;
namespace CryptographyCore = winrt::Windows::Security::Cryptography::Core;

REACT_MODULE(RNFetchBlob, L"RNFetchBlob");
struct RNFetchBlob
{

public:

	REACT_CONSTANT_PROVIDER(ConstantsViaConstantsProvider);
	void RNFetchBlob::ConstantsViaConstantsProvider(
		winrt::Microsoft::ReactNative::ReactConstantProvider& constants) noexcept;

	// createFile
	REACT_METHOD(createFile);
	winrt::fire_and_forget createFile(
		std::string path,
		std::wstring content,
		std::string encoding,
		winrt::Microsoft::ReactNative::ReactPromise<std::string> promise) noexcept;

	REACT_METHOD(createFileASCII);
	winrt::fire_and_forget createFileASCII(
		std::string path,
		winrt::Microsoft::ReactNative::JSValueArray dataArray,
		winrt::Microsoft::ReactNative::ReactPromise<std::string> promise) noexcept;

	
	// writeFile
	REACT_METHOD(writeFile);
	winrt::fire_and_forget writeFile(
		std::string path,
		std::string encoding,
		std::wstring data,
		bool append,
		winrt::Microsoft::ReactNative::ReactPromise<int> promise) noexcept;

	REACT_METHOD(writeFileArray);
	winrt::fire_and_forget writeFileArray(
		std::string path,
		winrt::Microsoft::ReactNative::JSValueArray dataArray,
		bool append,
		winrt::Microsoft::ReactNative::ReactPromise<int> promise) noexcept;


	// writeStream



	// readStream



	// mkdir
	REACT_METHOD(mkdir);
	void mkdir(
		std::string path,
		winrt::Microsoft::ReactNative::ReactPromise<bool> promise) noexcept;


	// readFile
	REACT_METHOD(readFile);
	winrt::fire_and_forget readFile(
		std::string path,
		std::string encoding,
		winrt::Microsoft::ReactNative::ReactPromise<std::wstring> promise) noexcept;


	// hash
	REACT_METHOD(hash);
	winrt::fire_and_forget hash(
		std::string path,
		std::string algorithm,
		winrt::Microsoft::ReactNative::ReactPromise<std::string> promise) noexcept;
	
	// ls
	REACT_METHOD(ls);
	winrt::fire_and_forget ls(
		std::string path,
		winrt::Microsoft::ReactNative::ReactPromise<std::vector<std::string>> promise) noexcept;


	// mv
	REACT_METHOD(mv);
	winrt::fire_and_forget mv(
		std::string src, // from
		std::string dest, // to
		std::function<void(std::string)> callback) noexcept;


	// cp
	REACT_METHOD(cp);
	winrt::fire_and_forget cp(
		std::string src, // from
		std::string dest, // to
		std::function<void(std::string)> callback) noexcept;


	// exists
	REACT_METHOD(exists);
	void exists(
		std::string path,
		std::function<void(bool, bool)> callback) noexcept;


	// unlink
	REACT_METHOD(unlink);
	winrt::fire_and_forget unlink(
		std::string path,
		std::function<void(std::string, bool)> callback) noexcept;


	// lstat
	REACT_METHOD(lstat);
	winrt::fire_and_forget lstat(
		std::string path,
		winrt::Microsoft::ReactNative::ReactPromise<winrt::Microsoft::ReactNative::JSValueArray> promise) noexcept;


	// stat
	REACT_METHOD(stat);
	winrt::fire_and_forget stat(
		std::string path,
		std::function<void(std::string, winrt::Microsoft::ReactNative::JSValueObject&)> callback) noexcept;


	// asset - appears to be Android only
	//REACT_METHOD(asset);
	//winrt::fire_and_forget asset(
	//	std::string filename,
	//	winrt::Microsoft::ReactNative::ReactPromise<std::string> promise) noexcept;


	// df
	REACT_METHOD(df);
	winrt::fire_and_forget df(
		std::function<void(std::string, winrt::Microsoft::ReactNative::JSValueObject&)> callback) noexcept;


// Helper methods
private:
	constexpr static int64_t UNIX_EPOCH_IN_WINRT_SECONDS = 11644473600;

	const std::map<std::string, std::function<CryptographyCore::HashAlgorithmProvider()>> availableHashes{
		{"md5", []() { return CryptographyCore::HashAlgorithmProvider::OpenAlgorithm(CryptographyCore::HashAlgorithmNames::Md5()); } },
		{"sha1", []() { return CryptographyCore::HashAlgorithmProvider::OpenAlgorithm(CryptographyCore::HashAlgorithmNames::Sha1()); } },
		{"sha256", []() { return CryptographyCore::HashAlgorithmProvider::OpenAlgorithm(CryptographyCore::HashAlgorithmNames::Sha256()); } },
		{"sha384", []() { return CryptographyCore::HashAlgorithmProvider::OpenAlgorithm(CryptographyCore::HashAlgorithmNames::Sha384()); } },
		{"sha512", []() { return CryptographyCore::HashAlgorithmProvider::OpenAlgorithm(CryptographyCore::HashAlgorithmNames::Sha512()); } }
	};

	void splitPath(const std::string& fullPath,
		winrt::hstring& directoryPath,
		winrt::hstring& fileName) noexcept;

	//void splitPath(const winrt::hstring& fullPath,
	//	winrt::hstring& directoryPath,
	//	winrt::hstring& folderName) noexcept;

};
