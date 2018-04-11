;;; Directory Local Variables
;;; For more information see (info "(emacs) Directory Variables")

((c++-mode
  (flycheck-clang-language-standard . "c++17" ))
 (c-mode
  (mode . c++)))

(setq auto-mode-alist (cons '("\\.tpp\'" . c++-mode) auto-mode-alist))
(setq auto-mode-alist (cons '("\\.ipp\'" . c++-mode) auto-mode-alist))
(add-hook 'python-mode-hook (lambda () (setq py-python-command "python3")))
