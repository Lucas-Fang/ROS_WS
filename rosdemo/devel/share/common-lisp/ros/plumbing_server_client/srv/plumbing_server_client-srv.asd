
(cl:in-package :asdf)

(defsystem "plumbing_server_client-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "ADDInts" :depends-on ("_package_ADDInts"))
    (:file "_package_ADDInts" :depends-on ("_package"))
  ))