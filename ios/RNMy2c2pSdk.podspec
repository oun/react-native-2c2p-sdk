
Pod::Spec.new do |s|
  s.name         = "RNMy2c2pSdk"
  s.version      = "1.0.0"
  s.summary      = "RNMy2c2pSdk"
  s.description  = <<-DESC
                  RNMy2c2pSdk
                   DESC
  s.homepage     = "https://my.2c2p.com"
  s.license      = "MIT"
  # s.license      = { :type => "MIT", :file => "FILE_LICENSE" }
  s.author             = { "author" => "author@domain.cn" }
  s.platform     = :ios, "7.0"
  s.source       = { :git => "https://github.com/author/RNMy2c2pSdk.git", :tag => "master" }
  s.source_files  = "RNMy2c2pSdk/**/*.{h,m}"
  s.requires_arc = true


  s.dependency "React"
  #s.dependency "others"

end

  
